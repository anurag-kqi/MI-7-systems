struct laptop
{
    int id;
    char model[20];
    int price;
};
void
main()
{
    struct laptop lenovo;
    printf("enter laptop details\n");
    
    printf("ente id\n");
    scanf("%d",&lenovo.id);
    printf("enter model\n");
    scanf("%s",&lenovo.model);
    printf("enter price\n");
    scanf("%d",&lenovo.price);
    
    printf("laptop details=%d : %s : %d",lenovo.id,lenovo.model,lenovo.price);
}
