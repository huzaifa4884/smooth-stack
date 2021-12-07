echo "building a docker image from docker file"
docker build -f Dockerfile -t dockerdev .
echo "spining up docker image" 
docker run -it -v /home:/home --name docker_dev_cont -d dockerdev
echo "executing docker"
docker exec -it dockerdev docker_dev_cont bash
