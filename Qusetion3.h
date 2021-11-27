#ifndef FINDREPEATNUMBER_H
#define FINDREPEATNUMBER_H
class FindRepeatNumber
{
public:
    bool static duplicate(int numbers[], int length, int* duplication)
    {
        if(numbers == nullptr || length <= 0)
        {
            return false;
        }

        for(int i = 0; i < length; i++)
        {
            if(numbers[i] < 0 || numbers[i] > length-1)
            {
                return false;
            }
        }

        for(int i = 0; i < length; i++)
        {
            while (numbers[i] != i) {
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }

                //swap numbers[i] and numbers[numbers[i]]
                int term = numbers[i];
                numbers[i] = numbers[term];
                numbers[term] = term;
            }
        }

        return false;
    }
};

#endif // FINDREPEATNUMBER_H
