#!/bin/bash

clang-format --style=google --Werror --dry-run src/* test/*
