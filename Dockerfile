FROM ubuntu
COPY myfile.sh .
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install vim -y
