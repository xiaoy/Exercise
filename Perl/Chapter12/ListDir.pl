opendir(ETC, "c:/") || die "no c:$!";
foreach $name (sort readdir(ETC)) {
    print "$name\n"
}
closedir(ETC);


