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
                        sh 'chmod +x ./build_bash.sh'
                        sh './build_bash.sh'
                        archiveArtifacts artifacts: 'build/bin/*', fingerprint: true
                    } catch (Exception e) {
                        error "Setup failed. Check the logs for details."
                    }
                }
            }
        }
    }

    post {
        success {
            echo 'Build completed successfully.'
        }
        failure {
            echo 'Build failed. Check the logs for details.'
        }
    }
}
