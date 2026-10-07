void main()
{
    unsigned char seg[10] = {
     0xC0,0xF9,0xA4,0xB0,0x99,
        0x92,0x82,0xF8,0x80,0x90
    };
    unsigned char digit[6]; 
    unsigned char sec = 0, min = 28, hr = 17;
    unsigned char i;
    unsigned int j;
    TRISD = 0x00;   
    TRISB = 0x00;  
    PORTD = 0x00;
    PORTB = 0x00;
    while(1)
    {
        digit[0] = hr / 10;
        digit[1] = hr % 10;
        digit[2] = min / 10;
        digit[3] = min % 10;
        digit[4] = sec / 10;
        digit[5] = sec % 10;
        for(j = 0; j < 50; j++) 
        {
            for(i = 0; i < 6; i++)
            {
                PORTB = (1 << i);       
                PORTD = seg[digit[i]];    
                Delay_ms(2);
            }
        }
        sec++;
        if(sec == 60)
        {
            sec = 0;
            min++;
            if(min == 60)
            {
                min = 0;
                hr++;

                if(hr == 24)
                    hr = 0;
            }
        }
    }
}