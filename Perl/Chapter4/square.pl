#load the table
srand;
open(NUMLIST, "table.txt") || die "open file failed";
@num_arr = ();
# random a number
while($num = <NUMLIST>) {
    push(@num_arr, $num);
}
#  print the square of the number
for($i = 0; $i < 32; ++$i) {
    #$a = $num_arr[$index];
    $b = GetTimesOfNum($i, 2);
    printf "%5g %8g\n", $i, $b;
}

foreach $num (0..32) {
    $squre = $num * $num;
    printf "%5g %8g\n", $num, $squre;
}
# the square of a number function

sub GetTimesOfNum {
    my($num, $times) = @_;
    # print "$num, $times\n";
    return $num ** $times;
}
