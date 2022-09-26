#!groovy

pipeline {
    environment {
        PROJECT_NAME = "SCP_Welcome"
    }

    options {
        timestamps()
        timeout(time: 1, unit: 'HOURS')
        skipDefaultCheckout()
    }

    agent {
        docker {
            alwaysPull true
            image 'espressif/idf:release-v4.4'
            args "--entrypoint=\'\' -u0:0"
            label "BUILDSERVER"
        }
    }

    stages {
        stage ('clone standard') {
            steps{
                sh "env | sort"
                sh "chmod 777 ."
                sh "rm -rf build"

                checkout ([
                        $class: 'GitSCM',
                        branches:  scm.branches,
                        /*doGenerateSubmoduleConfigurations: false, */
                        extensions: [
                                [$class: 'LocalBranch', localBranch: '**'],
                                /*[$class: 'PruneStaleBranch'],*/
                                [$class: 'CheckoutOption', timeout: 12],
                                [$class: 'CleanBeforeCheckout',
                                    deleteUntrackedNestedRepositories: true
                                ],
                                [$class: 'SubmoduleOption',
                                    disableSubmodules: false,
                                    parentCredentials: true,
                                    recursiveSubmodules: true,
                                    reference: '',
                                    trackingSubmodules: false
                                ]
                        ],
                        userRemoteConfigs: scm.userRemoteConfigs
                    ])
                sh 'git config --global --add safe.directory ${WORKSPACE}'
                sh 'git submodule update --init --recursive'
            }
        }

        stage ('Build') {
            steps {
                sh '/bin/bash -c "source /opt/esp/idf/export.sh &&  idf.py all"'
            }
        }

        stage ('Distribution') {
            steps {
                sh '/bin/bash -c "export DATE=`date +%Y%m%d-%H%M` && zip SCP_Welcome-\\$DATE.zip build/scp_welcome.bin build/partition_table/partition?table.bin build/bootloader/bootloader.bin"'
            }
        }
    }
 
    post {
        success {
            archiveArtifacts artifacts: '**/*.zip', fingerprint: true
        }
    }
}
