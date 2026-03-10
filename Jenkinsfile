pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Build') {
            steps {
                script {
                    try {
                        sh 'make'
                        archiveArtifacts artifacts: 'build/bin/*', fingerprint: true
                    } catch (Exception e) {
                        error "Build failed. Check the logs for details."
                    }
                }
            }
        }
        stage('Test') {
            steps {
                script {
                    try {
                        sh 'chmod +x build-tests/bin/*'
                        sh './build-tests/bin/unittests'
                    } catch (Exception e) {
                        error "Tests failed. Check the logs for details."
                    }
                }
            }
        }
    }

    post {
        success {
            echo 'Validation completed successfully.'
        }
        failure {
            echo 'Validation failed. Check the logs for details.'
        }
    }
}
