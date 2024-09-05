#!/bin/bash
groups $(id -un $FT_USER) | sed 's/^[^:]*: //' | tr ' ' ',' | sed 's/,$//'

groups $FT_USER | tr ' ' , | tr -d '\n'
