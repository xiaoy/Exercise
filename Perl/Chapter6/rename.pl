
$index = 100;
while($name = <*.log>) {
    rename($name, $index++);
}
