#!/bin/bash
git add *
git status 
git commit -m "`date +%m%d-%H%M`"
git push
