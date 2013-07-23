$pwd = <stdin>;
chomp($pwd);

chdir($pwd) || die "change dir failed";
foreach(<*>) {
    print "$_\n";
}
