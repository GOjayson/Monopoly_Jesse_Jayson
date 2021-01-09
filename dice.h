#ifndef DICE_H
#define DICE_H

namespace monopoly
{
    class dice
    {
        public:
            //constructor
            dice(const unsigned char aantal = 6) : sides(aantal){}
            ~dice(){}

            //public methods
            unsigned char gooidice();

        private:
            unsigned char sides;
    };
}

#endif // DICE_H
