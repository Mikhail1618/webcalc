#!/bin/bash

mkdir /root/.ssh
cat /keys/webcalc_server.pub > /root/.ssh/authorized_keys
/usr/sbin/sshd
catalina.sh run
