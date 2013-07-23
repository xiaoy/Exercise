#get file list

while($filename = <*.txt>) {
    $newname = time;
    rename($filename, "$newname.txt");
}
# rename file list 


#save file list

