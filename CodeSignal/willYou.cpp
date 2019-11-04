bool willYou(bool young, bool beautiful, bool loved) {
    return (young==true && beautiful==true && loved==false || loved==true && (young==false || beautiful==false));
}
