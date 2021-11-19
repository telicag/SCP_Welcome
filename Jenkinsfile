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
        }
    }

    stages {
        stage ('clone standard') {
            steps{
                sh "env | sort"
                sh 'sudo -S chmod 777 . | echo telic'
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
                sh 'git status'
                sh 'git submodule update --init --recursive'
                sh 'echo git success'
            }
        }

        stage ('Build') {
            steps {
                sh 'idf.py all'
            }
        }

        stage ('Distribution') {
            steps {
                sh 'echo python project/do_distribute.py'
            }
        }
    }
}