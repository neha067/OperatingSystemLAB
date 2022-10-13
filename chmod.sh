#read a file and change permissions...
    read f
    if [ -e $f ] 
    then echo "File Exists!"
    else   echo "File does not Exist" && exit
    fi
    if [ -w $f ] && [ -r $f ] 
     chmod 777 $f && echo "File Permission has been changed"
    fi


