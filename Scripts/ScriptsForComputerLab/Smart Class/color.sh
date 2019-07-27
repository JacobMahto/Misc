#!/usr/bin/env bash
#AUTHOR @ J. MAHTO , 15 JULY,2019
#DESCRIPTION : Smart Class Desktop Script to be start and initialize "color" software in linux Environment with automatic source code updation except (assets , which should be manually copied through a USB drive)
#PRE-REQUISITES ARE : 
#1. Programs to be installed : a. "XAMPP"	b. "FIGLET"	c."GIT"		d. "Google Chrome"
#2. "color" repository should be placed in /opt/lampp/htdocs/github/
#3. Incase , option #2 hasn't been maintained, then it will be done automatically

function establishRepository(){
	echo "Cloning repository from GITHUB";
	sleep 10;
	cd /opt/lampp/htdocs;
	mkdir github;
	cd github;
	git clone https://www.github.com/JacobMahto/color.git
	echo "REPOSITORY CLONED";
}

cd /opt/lampp/htdocs/github/color || (echo "Repository doesn't exists." ; establishRepository; )
sudo git pull || establishRepository
cd /opt/lampp
sudo ./lampp startapache
sudo ./lampp startmysql
echo "Connecting To www.jacob-tech.com"
sleep 5
sudo ./bin/mysql -e "drop database color"
sudo ./bin/mysql -e "create database color"
sudo ./bin/mysql color</opt/lampp/htdocs/github/color/assets/color.sql
figlet "Welcome jvm"
google-chrome "localhost/github/color/class_sel.php"
sleep 5
