srand;

print "say some thing:";
@words = <stdin>;
$index = rand(@words);
print "$words[$index]";
