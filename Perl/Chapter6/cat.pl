
#foreach $filename (@ARGV) {
#    open(LINES, $filename) || die "open file $filename failed";
#    while($line = <LINES>) {
#        print $line, "\n";
#    }
#}

@ARGV = reverse @ARGV;

print reverse <>;
