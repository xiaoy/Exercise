#  the hash test


# input your user name
print "input your user name:";
$username = <stdin>;

chomp($username);
# initiate the hash map of user

#%usermap = qw(
#   lfwu    123
#   gyy     345
#   xiaoy   nima
#);

InitWordList();
# find the user 
if($username =~ /^admin\b/i){
    print "Hello, admin! how good of you to be here!\n";
}else{
    print "hello, $username!\n";
    # $pwd = $usermap{$username};
    print "input your pwd:";

    $guess = <stdin>;
    chomp($guess);
    # while($guess ne $pwd) {
    #    print "Wrong, try again, what is secret pwd:";
    #    $guess = <stdin>;
    #    chomp($guess);
    #}
    while(!good_word($username, $guess)) {
        print "Wrong, try again, what is secret pwd:";
        $guess = <stdin>;
        chomp($guess);
    }
    print "Login success\n";
}
sub InitWordList{
    open(WORDLIST, "wordlist.txt");
    while(defined($name = <WORDLIST>)) {
        chomp($name);
        $pwd = <WORDLIST>;
        chomp($pwd);
        $usermap{"$name"} = $pwd;
        print "username:$name, pwd:$pwd\n";
    }
    close(WORDLIST);
}
sub good_word{
    my($username, $pwd) = @_;
    if($usermap{$username} eq $pwd) {
        return 1;
    }elsif(($usermap[$username] || "father") eq $pwd) {
        return 1;
    }else {
        open(MAIL, "|mail lfwu");
        print MAIL "bad news:$username guessed $pwd\n";
        close MAIL;
        return 0;
    }
}
# verify password and login 
