#ifndef MOVIE_DISPLAY_H
#define MOVIE_DISPLAY_H
#include <string>
#include <iostream>
// Helper class for beautiful console output
class MovieDisplay
{
public:
    // Different rating display styles
    enum RatingStyle
    {
        STYLE_BARS,    // [*****] or [***--]
        STYLE_BLOCKS,  // [?????] or [?????]
        STYLE_NUMBERS, // 5.0/5.0
        STYLE_DOTS,    // [�����] or [�����]
        STYLE_PLUS     // [+++++] or [+++  ]
    };
    // Display rating with selected style
    static std::string getRatingDisplay(int rating, RatingStyle style = STYLE_BARS)
    {
        std::string result = "[";
        switch (style)
        {
        case STYLE_BARS:
            for (int i = 0; i < rating; i++)
                result += "*";
            for (int i = rating; i < 5; i++)
                result += "-";
            break;
        case STYLE_BLOCKS:
            for (int i = 0; i < rating; i++)
                result += "#";
            for (int i = rating; i < 5; i++)
                result += ".";
            break;
        case STYLE_NUMBERS:
            result = "";
            return std::to_string(rating) + ".0/5.0";
        case STYLE_DOTS:
            for (int i = 0; i < rating; i++)
                result += "o";
            for (int i = rating; i < 5; i++)
                result += ".";
            break;
        case STYLE_PLUS:
            for (int i = 0; i < rating; i++)
                result += "+";
            for (int i = rating; i < 5; i++)
                result += " ";
            break;
        }
        result += "] " + std::to_string(rating) + "/5";
        return result;
    }
    // Draw a fancy box around text
    static void drawBox(const std::string &title, int width = 100)
    {
        std::cout << std::string(width, '=') << std::endl;
        int padding = (width - title.length()) / 2;
        std::cout << std::string(padding, ' ') << title << std::endl;

        std::cout << std::string(width, '=') << std::endl;
    }

    // Draw separator line
    static void drawLine(char character = '-', int width = 100)
    {
        std::cout << std::string(width, character) << std::endl;
    }
};

#endif // MOVIE_DISPLAY_H
