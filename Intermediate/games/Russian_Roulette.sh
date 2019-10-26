#!/bin/bash

PUM="BANG BANG"
CLICK="Lucky guy"

[ $(( $RANDOM % 5 )) -eq 0 ] && echo $PUM || echo $CLICK
