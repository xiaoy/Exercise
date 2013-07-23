#print "input your name:";
#$name = <stdin>;
#chomp($name);
#format TEXT =
#Welcome @<<<<<<<<<< lgoin 
#$name
#print TEXT;
format ADDRESSLABEL = 
===============================
| @<<<<<<<<<<<<<<<<<<<<<<<<<<< |
$name
| @<<<<<<<<<<<<<<<<<<<<<<<<<<< |
$address
| @<<<<<<<<<<<<<<<, @< @<<<<<< |
$city,          $state, $zip
===============================
.
open(ADDRESSLABEL, ">labels-to-print") || die "can't create";
open(ADDRESS,   "addresses.txt");
while(<ADDRESS>) {
    chomp;
    ($name, $address, $city, $state, $zip) = split(/:/);
    write(ADDRESSLABEL);
}
