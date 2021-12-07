FROM centos:8

RUN yum update -y
RUN yum -y install vim
RUN yum -y install nano
RUN yum -y install gdb
RUN yum -y install tree
RUN yum -y install clang
Run yum -y install make

COPY .bashrc /root/.bashrc


RUN source /root/.bashrc


