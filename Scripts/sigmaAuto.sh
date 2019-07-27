#/bin/bash
USER='username'
PASSWORD='password'
read -p "Enter Username : " USER
read -p "Enter password : " PASSWORD

pftp -nv files.000webhost.com<<HULULU
quote USER $USER
quote PASS $PASSWORD
cd public_html/report
put rpt.html
quit
HULULU
