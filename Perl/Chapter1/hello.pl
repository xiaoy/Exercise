#first perl programer

#  input the user name
print "input your name:";

$username = <stdin>;
chomp($username);

print "welcome $username, and input your pwd:";

$pwd = <stdin>;
chomp($pwd);
#  define user pwd arr
@pwdArr = qw(123 xiaoy_pandn wulongfei);
$index = 0;

$correct = "maybe";

# verify user pwd

while($correct eq "maybe") {
    if($pwdArr[$index] eq $pwd) {
        $correct = $pwd;
    } elsif($index < 2) {
        $index = $index + 1;
    }else {
        print "the pwd wrong, input again:";
        $pwd = <stdin>;
        chomp($pwd);
        $index = 0;
    }
}

# print welcome user message
print "your pwd is correct";



