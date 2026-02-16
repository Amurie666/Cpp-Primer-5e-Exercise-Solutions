#pragma once
#include "../UniQuery/WordQuery.h"
#include "../QueryResult.h"
#include "../BiQuery/AndQuery.h"
#include "../QueryBase.h"
#include "../BiQuery/OrQuery.h"
#include "../UniQuery/NotQuery.h"

class Query
{
public:
    friend Query operator&(const Query &lhs, const Query &rhs);
    friend Query operator|(const Query &lhs, const Query &rhs);
    friend Query operator~(const Query &op);
    friend std::ostream &operator<<(std::ostream &out, const Query &qry);
    QueryResult evaluate() const;
    std::string parameters() const;
    Query(const std::string wrd) : result(std::make_shared<WordQuery>(WordQuery(wrd)))
    {
        std::cout << "Query(const std::string wrd)" << std::endl;
    }

private:
    Query(std::shared_ptr<const QueryBase> qry_opp) : result(qry_opp)
    {
        std::cout << "Query(std::shared_ptr<const QueryBase> qry_opp)" << std::endl;
    }
    std::shared_ptr<const QueryBase> result;
};

/* IGNOREEEEEEEE THISSSSSSSSSSSSSSSS
Query process_or(std::string leftarg, std::string rightarg)
{
}

class Process
{
private:
    std::string query;
    static const std::set<std::string> erroneous_ops;
    static const std::set<char> ops;
    int first_clsd_paren = 0;
    int last_opn_paren = 0;
    std::vector<int> opn_parens = {};
    std::vector<int> clsd_parens = {};

public:
    Process(std::string qry) : query(qry)
    {
        if (qry.length() == 0)
            throw std::runtime_error("Invalid Query.");
        auto first = qry[0];
        auto last = qry[qry.length() - 1];
        // Our fastest tickets to an invalid query.^^
        // A:
        if (
            first == '&' | first == '|' |
            first == ')' | last == '&' |
            last == '|' | last == '~' |
            last == '(')
            throw std::runtime_error("Invalid Query.");
        // And B:
        if (qry.length() != 1)
            for (int i{0}; i < qry.length() - 2; ++i)
                if (erroneous_ops.find(qry.substr(i, 2)) != erroneous_ops.end())
                    throw std::runtime_error("Invalid Query.");
        // We can't have a query of the form: "... word(...)" or "...(...)word..." or "...(...)~".
        for (int i{0}; i < qry.length(); ++i)
        {
            if (qry[i] == '(' && i != 0)
                if (ops.find(qry[i - 1]) == ops.end())
                    throw std::runtime_error("Invalid Query.");
            if (qry[i] == ')' && i != qry.length() - 1)
                if ((ops.find(qry[i + 1]) == ops.end()) | (qry[i + 1] == '~'))
                    throw std::runtime_error("Invalid Query.");
        }
        for (int i{0}; i < qry.length(); ++i)
            if (qry[i] == '(')
                opn_parens.push_back(i);
        for (int i{0}; i < qry.length(); ++i)
            if (qry[i] == ')')
                clsd_parens.push_back(i);
        if (clsd_parens.size() != 0)
            first_clsd_paren = *std::min_element(clsd_parens.begin(), opn_parens.end());
        if (opn_parens.size() != 0)
            last_opn_paren = *std::max_element(opn_parens.begin(), opn_parens.end());
        if (opn_parens.size() != clsd_parens.size())
            throw std::runtime_error("Invalid Query.");
    }
    /*
    Query evaluate()
    {
        if (first_clsd_paren != 0)
        {
        }
    }
    Query evaluateAnds(std::string base_qry, const std::vector<int>& ands)
    {
        if(ands[0] == 0) {
            if(base_qry[0] == '~') {
                return base_qry.substr(1, ands[1]) & evaluateAnds(, )
            }
        }
    }
    Query evaluate_base(std::string base_qry)
    {

        std::set<int> Not_occur = {};
        std::set<int> And_occur = {};
        std::set<int> Or_occur = {};

        for (int i{0}; i < base_qry.length(); ++i)
        {
            if (base_qry[i] == '~')
                Not_occur.insert(i);
            if (base_qry[i] == '&')
                And_occur.insert(i);
            if (base_qry[i] == '|')
                Or_occur.insert(i);
        }
        // assuming base_qry is in a valid format... !a|b&q|!c&f
        std::map<int, Query> Not_loc;
        auto ib = 0;
        for (int i{0}; i < base_qry.length(); ++i)
        {
            if (base_qry[i] == '~')
            {
                for (int j{i + 1}; j < base_qry.length(); ++j)
                {
                    if (base_qry[j] == '&' | base_qry[j] == '|')
                        ib = j;
                    break;
                }
                Not_loc[i] = ~Query(base_qry.substr(i + 1, ib - i));
            }
        }

        auto AndSequences = partitionAndsWithBounds(And_occur, Or_occur);

        for (auto &seq : AndSequences)
        {
            if (seq[0] == 0)
                for (int i{1}; i < seq.size(); ++i)
                    if (seq[1] == '~')
                    {
                        auto neg_qry = Not_loc[1];
                    }
        }

        // example ~a|b&c&d&~e&s&|f|~c ....
        std::map<int, Query> And_loc;
        for (const auto &i : And_occur)
        {
            int right_bound = base_qry.length();
            int left_bound = 0;
            bool is_right_negated = base_qry[i + 1] == '~';
            bool is_left_negated;
            for (int j{i + 1}; j < base_qry.length(); ++j)
                if (base_qry[j] == '|')
                {
                    right_bound = j;
                    break;
                }
            for (int j{i - 1}; 0 <= j; --j)
                if (base_qry[j] == '|')
                {
                    left_bound = j;
                    is_left_negated = base_qry[j + 1] == '~';
                    break;
                }
        }
    };

    class Process_base {

    };

    ////////////////////////////////////////////////////////////////

    std::vector<std::vector<int>> partitionAndsWithBounds(
        const std::set<int> &And_occur,
        const std::set<int> &Or_occur)
    {
        std::vector<std::vector<int>> result;
        if (And_occur.empty())
            return result;

        auto orBegin = Or_occur.begin();
        auto orEnd = Or_occur.end();

        auto prevOr = (Or_occur.empty() ? 0 : *orBegin);
        auto nextOr = (Or_occur.empty() ? 0 : *orBegin);
        auto itOr = orBegin;
        if (itOr != orEnd)
            ++itOr;

        std::vector<int> group;
        int prevAnd = -1;

        for (int x : And_occur)
        {
            // move OR window so that prevOr < x < nextOr
            while (itOr != orEnd && x > *itOr)
            {
                prevOr = nextOr;
                nextOr = *itOr;
                ++itOr;
            }

            if (!group.empty() && x != prevAnd + 1)
            {
                // close group
                std::vector<int> bounded;
                bounded.push_back(prevOr);
                bounded.insert(bounded.end(), group.begin(), group.end());
                bounded.push_back(nextOr);
                result.push_back(bounded);
                group.clear();
            }

            group.push_back(x);
            prevAnd = x;

            bool beforeFirst = Or_occur.empty() ? true : (x < *orBegin);
            bool afterLast = Or_occur.empty() ? true : (x > *Or_occur.rbegin());

            if (beforeFirst || afterLast)
            {
                std::vector<int> bounded;
                bounded.push_back(0); // left bound absent
                bounded.insert(bounded.end(), group.begin(), group.end());
                bounded.push_back(0); // right bound absent
                result.push_back(bounded);
                group.clear();
            }
        }

        if (!group.empty())
        {
            std::vector<int> bounded;
            bounded.push_back(prevOr);
            bounded.insert(bounded.end(), group.begin(), group.end());
            bounded.push_back(nextOr);
            result.push_back(bounded);
        }

        return result;
    }

    //////////////////////////////////////////////////////////////

    const std::set<char> Process::ops = {'&', '~', '|'};
    const std::set<std::string> Process::erroneous_ops = {
        "&&", "~~", "||", "~&", "|&",
        "&|", "~|", ")~", "&)", "|)",
        "~)", "(&", "(|"};
    void validate(const std::string &qry)
    {
    }


    Query Query::process(std::string qry)
   {

           std::string inner_qry = qry.substr(opning_indx + 1);
           if (opning_indx != std::string::npos)
               process(inner_qry);
    }

*/

