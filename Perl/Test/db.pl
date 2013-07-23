use DBI;

## mysql user database name
$db = "zxdgamedata";

## mysql database use name
$user = "root";

## mysql database password
$pass = "123456";

## user hostname : this should be "localhost"
$host = "localhost";

## SQL query
$query = "show tables";

$dbh = DBI->connect("DBI:mysql:$db:$host", $user, $pass);
$sqlQuery = $dbh->prepare($query)
    or die "can't prepare $query: $dbh->errstr\n";

$rv= $sqlQuery->execue
    or die "can't execue the query: $sqlQuery->errstr";
while(@row = $sqlQuery->fetchrow_array()) {
    my $tables = $row[0];
    print "$tables\n<br>";
}

$rc = $sqlQuery->finish;
exit(0);
