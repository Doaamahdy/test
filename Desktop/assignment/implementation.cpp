#include "header.h"
bigInteger::bigInteger()
{
    signd = false;
    s = "";
    siz = s.size();
};
//----------------------------
bigInteger::bigInteger(int n)
{
    s = to_string(n);
    siz = s.length();
    signd = false;
    if(s[0] == '-'||s[0]=='+')
        siz--;
    if(s[0] == '-')
        signd = true;

    for(int i = 0;i < s.size();i++) 
    {
        if ((signd || s[0] == '+') && i == 0)
            continue;
        int num = s[i] - '0';
        v.push_back(num);
    }
}
//-----------------------------------
bigInteger::bigInteger(string str)
{
    s = str;
    siz = str.length();
    signd = false;
    if(s[0] == '-'||s[0]=='+')
        siz--;
    if(s[0] == '-')
        signd = true;

    for(int i = 0;i < s.size();i++) 
    {
        if((signd || s[0] == '+') && i == 0)
            continue;
        int num = s[i] - '0';
        v.push_back(num);
    }
}
//----------------------------
bigInteger bigInteger:: operator +(bigInteger d) 
{
    vector<int> v1;
    v1=(v);
    reverse(v1.begin(), v1.end());
    vector<int> v2(d.v);
     reverse(v2.begin(), v2.end());

    bigInteger ans;
    long long len = min(v1.size(), v2.size());
    long long cary = 0;
    if(signd && !d.signd)
    {
        bigInteger temp1 = *this,temp2 = d;
        temp1.signd = false; temp2.signd = false;
        ans = temp1 - temp2;
        if(temp1 > temp2)
            ans.signd = true;
        return ans;
    }
    else if(!signd && d.signd)
    {
        bigInteger temp1 = *this,temp2 = d;
        temp1.signd = false; temp2.signd = false;
        ans = temp1 - temp2;
        if(temp1 < temp2)
            ans.signd = true;
        return ans;
    }
    else 
    {
        for (int i = 0; i < len; i++)
         {
            int val = v1[i] + v2[i] + cary;
            cary = val / 10;
            ans.v.push_back(val % 10);
        }
        if (v1.size() > len) 
        {
            for (int i = len; i < v1.size(); i++) 
            {
                int val = v1[i] + cary;
                cary = val / 10;
                ans.v.push_back(val % 10);
            }
        }
        if (v2.size() > len) 
        {
            for (int i = len; i < v2.size(); i++) 
            {
                int val = v2[i] + cary;
                cary = val / 10;
                ans.v.push_back(val % 10);
            }
        }

        while (cary) 
        {
            ans.v.push_back(cary % 10);
            cary /= 10;
        }
        if (d.signd && signd)
            ans.signd = true;
        reverse(ans.v.begin(), ans.v.end());
        return ans;
    }
}
//------------------------------------
bigInteger bigInteger:: operator -(bigInteger d){

    vector<int> v1;
    vector<int> v2;
    if(siz > d.siz){
        v1 = v;
        v2 = d.v;
        }
        else
        {
        v1 = d.v;
        v2 = v;
        }

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    bigInteger ans;
    long long len = min(v1.size(), v2.size());
    long long cary = 0;

    bigInteger temp1 = *this,temp2 = d;
    temp1.signd = false; temp2.signd = false;

    if(!signd && d.signd)
    {
        bigInteger temp1 = *this,temp2 = d;
        temp1.signd = false; temp2.signd = false;
        ans = temp1 + temp2;
        ans.signd = false;
        return ans;
    }
    else if(signd && !d.signd)
    {
        bigInteger temp1 = *this,temp2 = d;
        temp1.signd = false; temp2.signd = false;
        ans = temp1 + temp2;
        ans.signd = true;
        return ans;
    }
    else 
    {
        for (int i = 0; i < len; i++) 
        {
            if (v1[i] < v2[i])
            {
                v1[i + 1]--;
                ans.v.push_back(10 + v1[i] - v2[i]);
            } 
            else
                ans.v.push_back(v1[i] - v2[i]);
        }
        if (v1.size() > len) 
        {
            for (int i = len; i < v1.size(); i++) {
                if (v1[i] < 0)
                {
                    v1[i + 1]--;
                    ans.v.push_back(10 + v1[i]);
                }
                    else 
                    {
                        ans.v.push_back(v1[i]);
                    }
                }
            }
        reverse(ans.v.begin(), ans.v.end());
        bigInteger result;
        int i = 0;
        while(ans.v[i] == 0 && i != ans.v.size()-1)i++;
        for(;i < ans.v.size() ;i++)
            result.v.push_back(ans.v[i]);

        if((!signd && !d.signd) && temp1 < temp2 )
            result.signd = true;
        else if((signd && d.signd) && temp2 < temp1 )
            result.signd = true;
        else result.signd = false;
        return result;
    }

}
//---------------
bool bigInteger:: operator ==(bigInteger obj)
{
    if(s == obj.s)
        return true;
    else
        return false;
}
//---------------------
bool bigInteger:: operator >(bigInteger obj)
{
    if(!signd && !obj.signd)
    {
        if(siz == obj.siz)
        {
            for(int i = 0;i < siz;i++)
            {
                if(v[i] < obj.v[i])
                    return false;
                else if(v[i] > obj.v[i])
                    break;
            }
        }
        else
        {
            if(siz < obj.siz)
            {
                return false;
            }
        }
        return true;
    }
    else if(signd && obj.signd)
    {
        if(siz == obj.siz)
        {
            for(int i = 0;i < siz;i++)
            {
                if(v[i] > obj.v[i])
                    return false;
                else if(v[i] < obj.v[i])
                    break;
            }
        }
        else
        {
            if(siz > obj.siz){
                return false;
            }
        }
        return true;
    }
     else if(signd && !obj.signd)
        return false;
    else if (!signd && obj.signd)
        return true;
    return true;
}
//-----------------------------
bool bigInteger:: operator <(bigInteger obj)
{
    if(!signd && !obj.signd)
    {
        if(siz == obj.siz)
        {
            for(int i = 0;i < siz;i++)
            {
                if(v[i] > obj.v[i])
                    return false;
                else if(v[i] < obj.v[i])
                    break;
            }
        }
        else
        {
            if(siz > obj.siz)
            {
                return false;
            }
        }
            return true;
    }
    else if(signd && obj.signd)
    {
        if(siz == obj.siz)
        {
            for(int i = 0;i < siz;i++)
            {
                if(v[i] < obj.v[i])
                    return false;
                else if(v[i] > obj.v[i])
                    break;
            }
        }
        else
        {
            if(siz < obj.siz)
            {
                return false;
            }
        }
        return true;
    }
    else if(!signd && obj.signd)
        return false;
    else if (signd && !obj.signd)
        return true;
    return true;
}
//--------------------------------
bigInteger bigInteger:: operator =(bigInteger obj)
{
    s = obj.s;
    v = obj.v;
    signd = obj.signd;
    siz  = obj.siz;
    return obj;
}
//----------------------------------
int bigInteger::size()
{
    return siz;
}
//----------------------------------
int bigInteger:: sign()
{
    if(signd) {return 1;}
    return 0;
}
//--------------------------------------
ostream& operator << (ostream& output , bigInteger d)
{
    if(d.signd) cout << "-";
    for(int i = 0;i < d.v.size();i++)
        cout << d.v[i];
    return output;
}
//-----------------------------------------
istream&  operator >> (istream&input , bigInteger& d)
{
    input >> d.s;
    return input;
}