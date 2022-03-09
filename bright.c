#include "bright.h" 

void
usage()
{
    printf("Usage:\n");
    printf("       bright -[i][d][s <percentage>][h]\n");
    printf("-i, --increment             Increase brightness by 10%\n");
    printf("-d, --decrement             Decrease brightness by 10%\n");
    printf("-s, --set <percentage>      Set brightness to desired percentage\n");
    printf("-h, --help                  print this message\n");
    exit(1);
}


int
main (int argc, char* argv[])
{
    int c_opts;
    FILE *fd = fopen(BACKLIGHT_FILE,"r+");
    if (fd == NULL){
        fprintf(stderr, "Unable to open file\n");
        exit(1);
    }
    
    void* amount = (char*) malloc(sizeof(char)*128);
    fread(amount, sizeof(amount), 1, fd);
    int val = atoi((char*)amount);
    free(amount);

    while(1){
        static struct option long_options[] = 
        {
            {"increment", no_argument      , 0, 'i'},
            {"decrement", no_argument      , 0, 'd'},
            {"help"     , no_argument      , 0, 'h'},
            {"set"      , required_argument, 0, 's'},
            {0, 0, 0, 0}
        };
        int option_index = 0;

        c_opts = getopt_long(argc, argv, "idhs:",
                             long_options, &option_index);

        if (c_opts == -1) break;
        
        switch(c_opts)
        {
            case 0:
                if (long_options[option_index].flag != 0) break;
                printf("option %s", long_options[option_index].name);
                if (optarg) printf(" with arg %s", optarg);
                printf("\n");
                break;
            case 'i':
                val += INC_BRIGHT;
                break;
            case 'd':
                val += DEC_BRIGHT;
                break;
            case 's':
                float temp_val = atof(optarg);
                temp_val *= MAX_BRIGHT;
                val = (int)temp_val;
                break; 
            case 'h':
                usage();
                break;
            default:
                usage();
        }
        if(val > MAX_BRIGHT) val = MAX_BRIGHT;
        if(val < 10) val = 10;
    }
    fprintf(fd,"%d", val);
    fclose(fd);
}
