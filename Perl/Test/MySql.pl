#f user lfwu
# Add privillage for other mysql visit local
# 2013/5/16
print "input mysql path:";
$path = <stdin>;
system("cd" . $path) == 0 or die "wrong path";
$host = "192.168.0.";
$login = "mysql -u root -p";
$use = "use zxdgamedata";
system($login) == 0 or die "password error";
print $login;
system($use) == 0 or die "the data base is not exsit";
print($use);
for($i = 100; $i < 101; $i = $i +1) {
    $target = $host . $i;
    $cmd = "grant all on *.* to root@"."'".$target."'". " identified by " ."'"."123456"."'";
    system($cmd);
    print($cmd . "\n");
}
