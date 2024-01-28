#!/bin/sh

find build -mindepth 1 -maxdepth 1 ! -name '_deps' -exec rm -rf {} +
rm -r out
