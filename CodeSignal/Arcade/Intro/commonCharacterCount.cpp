int commonCharacterCount(std::string s1, std::string s2)
{
    int a[150]={0},b[150]={0},i,j,num=0;
    for (i=0;i<s1.length();i++) a[s1[i]]++;
    for (i=0;i<s2.length();i++) b[s2[i]]++;
    for (i=97;i<=122;i++) num+=(a[i]>b[i])?b[i]:a[i];
    return num;
}
