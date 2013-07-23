$str = <stdin>;
chomp($str);
#$ret = ($str=~ /^ab+/);
#$ret = ($str=~ /\\+\**/);

#$whatever = "wokao";
#$ret = ($str=~ /($whatever)(\1)(\2)/);
#$ret = ($str=~ /\w{5}|\\n{5}/);


#$ret = ($str =~ //);
$ret = ($str =~ //);
print $str;
if($ret) {
    print "\nRight";
}else {
    print "\nWrong";
}

