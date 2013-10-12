//---------------------------------------------------------------------------
#ifndef DARKPATH_testerH
#define DARKPATH_testerH
//---------------------------------------------------------------------------
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
//---------------------------------------------------------------------------
template <typename o>
class tester
{
    public:
        typedef
            o
            output_type;
    private:
        output_type&        m_otOutput;
        std::vector<int>    mvec_iSection;
        int                 miTest;

        std::string currentSection()
        {
            assert(!mvec_iSection.empty());

            std::ostringstream s;

            for (
                unsigned int i = 0;
                i < mvec_iSection.size() - 1;
                ++i
            )
            {
                s   << mvec_iSection[i]
                    << ".";
            }

            s   << mvec_iSection.back();

            return std::string(s.str());
        }

    public:
        tester(o& output) :
            m_otOutput(output), mvec_iSection(), miTest(1)
        {
        }

        void beginSection(std::string title)
        {
            mvec_iSection.push_back(1);
            m_otOutput
                << std::string(2 * mvec_iSection.size() - 2, ' ')
                << currentSection() << ": "
                << title
                << std::endl;
        }

        void endSection()
        {
            assert(!mvec_iSection.empty());

            m_otOutput << std::endl;

            mvec_iSection.pop_back();

            if (!mvec_iSection.empty())
            {
                ++mvec_iSection.back();
            }
            miTest = 1;
        }

        void test(std::string title, bool condition)
        {
            m_otOutput
                << std::string(2 * mvec_iSection.size(), ' ')
                << miTest << ". "
                << title
                << std::endl
                << std::string(2 * mvec_iSection.size() + 2, ' ')
                << "... "
                << (condition ? "passed!" : "FAILED!")
                << std::endl;

            ++miTest;
        }
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------

