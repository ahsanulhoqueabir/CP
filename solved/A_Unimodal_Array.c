/*-----------------------------------------*
*      **      ** * *    * * *   * * *     *
*     *  *     *     *     *     *    *    *
*    ******    ******      *     ** **     *
*   *      *   *     *     *     *    *    *
*  *        *  ** * *    * * *   *     *   *
___________________________________________*/

#include<stdio.h>

int main()
{
   
    int n; scanf("%d",&n);
    int a[n];
    int c=n,j=0,p=0,q=n-1;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    while (a[p] < a[p+1] && p<n) p++;
    while(a[q] < a[q-1] && q > 0) q--;
    while(a[p] == a[p+1] && p < q) p++;
    
    if(p>=q) printf("YES");
    else printf("NO");

}