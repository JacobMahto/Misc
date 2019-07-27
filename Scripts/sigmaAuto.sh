#/bin/bash
USER='username'
PASSWORD='password'
TODAY='date'
read -p "Enter Username : " USER
read -p "Enter password : " PASSWORD
read -p "Enter date(yyyy-mm-dd) : " TODAY 

function repgen(){
#GETTING INDIVIDUAL CLASSES REPORT AND APPENDING TO SINGLE FILE
CLASSES="IX%20RBSE IX%20CBSE X%20RBSE X%20CBSE XI%20PCM XI%20PCB XII%20PCM XII%20PCB"
if [ -e 'rpt.html' ]
then
	rm rpt.html
	echo "rpt.html already existed. So DELETED."
fi
for STD in $CLASSES
do
echo "${STD} DOWNLOADING...."
curl --data "dt=${TODAY}&std=${STD}&repB=ATTENDANCE%20REPORT" https://sigmaeduindia.000webhostapp.com/report/attendWhatsapp.php>>rpt.html
echo "${STD} DOWNLOADED."
done
echo $?
if [ "$?" -eq "0" ]
then
	echo "DATA HAS BEEN DOWNLOADED."
fi
}
repgen
echo "UPLOADING TO SERVER NOW...."
pftp -nv files.000webhost.com<<HULULU
quote USER $USER
quote PASS $PASSWORD
cd public_html/report
put rpt.html
quit
HULULU
echo "EVERYTHING DONE.Logon to sigmaeduindia.000webhostapp.com/report/rpt.html"

