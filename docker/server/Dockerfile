FROM ubuntu:20.04 AS builder_gnuplot

ENV TZ=Europe/Minsk
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get -y upgrade \
 && apt-get -y install make gcc wget libgd-dev

WORKDIR /root
RUN wget https://fossies.org/linux/misc/gnuplot-5.4.2.tar.gz \
 && tar xzf gnuplot-5.4.2.tar.gz

WORKDIR /root/gnuplot-5.4.2
RUN ./configure && make && make install


FROM tomcat:9.0.50-jdk11

RUN apt-get update && apt-get -y upgrade \
 && apt-get -y install openssh-server g++ docker.io


COPY --from=builder_gnuplot /usr/local/bin/gnuplot /usr/local/bin/gnuplot

ENV LIBS=/lib/x86_64-linux-gnu
COPY --from=builder_gnuplot \
 $LIBS/libgd.so.3.0.5 \
 $LIBS/libjpeg.so.8.2.2 \
 $LIBS/libXpm.so.4.11.0 \
 $LIBS/libtiff.so.5.5.0 \
 $LIBS/libwebp.so.6.0.2 \
 $LIBS/libjbig.so.0 \
 $LIBS/libm-2.31.so \
 /lib/x86_64-linux-gnu

RUN ln -snf $LIBS/libgd.so.3.0.5 $LIBS/libgd.so.3 \
 && ln -snf $LIBS/libjpeg.so.8.2.2 $LIBS/libjpeg.so.8 \
 && ln -snf $LIBS/libXpm.so.4.11.0 $LIBS/libXpm.so.4 \
 && ln -snf $LIBS/libtiff.so.5.5.0 $LIBS/libtiff.so.5 \
 && ln -snf $LIBS/libwebp.so.6.0.2 $LIBS/libwebp.so.6 \
 && ln -snf $LIBS/libjbig.so.0 $LIBS/libjbig.so \
 && ln -snf $LIBS/libm-2.31.so $LIBS/libm.so.6

RUN mkdir /run/sshd

COPY ./sshd_config /etc/ssh/

COPY ./main.sh ./bin/

CMD ./bin/main.sh
