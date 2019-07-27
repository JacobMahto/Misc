#!/usr/bin/env bash
#AUTHOR : J. MAHTO , 16 JULY , 2019
#DESCRIPTION :Script for Copying "color" software assets to the destined location
#INSTRUCTIONS : Copy this script to the same Hierachial level as the folder "assets", for example if "assets" folder is situated in "xyz" folder , then this script must be copied to that folder and then executed. 
sudo cp -rvn assets /opt/lampp/htdocs/github/color/
echo "Task Completed"
