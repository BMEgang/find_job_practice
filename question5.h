#ifndef QUESTION5_H
#define QUESTION5_H
class replaceSpace
{
public:
    //length is the total capacity of the string array
   void replaceblank(char string[], int length)
   {
        if(string == nullptr || length < 0)
        {
            return;
        }
        /*originallength is the original length of string*/
        int originallength = 0;
        int numberofblank = 0;
        int i = 0;

        while (string[i] != '\0') {
            ++originallength;
            if(string[i] == ' ')
            {
                ++numberofblank;
            }
            ++i;
        }
        /*originallength is the original length of string*/
        int newlength = originallength + 2* numberofblank;
        if (newlength > length)
        {
            return;
        }

        int indexoforiginal = originallength;
        int indexofnew = newlength;
        while (indexoforiginal >= 0 && indexofnew > indexoforiginal) {
            if(string[indexoforiginal] == ' ')
            {
                string[indexofnew--]='0';
                string[indexofnew--]='2';
                string[indexofnew--]='%';
            }
            else {
                string[indexofnew--]=string[indexoforiginal];
            }

            --indexoforiginal;
        }
   }
};

#endif // QUESTION5_H
