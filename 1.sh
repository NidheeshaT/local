for file in "$@"
do
    if [ -f $file ] 
    then
        Ufile=`expr $file | tr '[a-z]' '[A-Z]'`
        echo $Ufile
        if [ -f $Ufile ]
        then
            echo "already present"
        else
            mv $file $Ufile
        fi
    else
        echo "ajsd"
    fi
done