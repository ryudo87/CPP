//string words[]={"aaa", "bbbbbb","cc","d","eeeee"};
int isspam()
{
	string msg="The vacancies below match your profile. If you like any of these vacancies then what are you waiting for? Apply now!";
	string pat[130][100];
	pat['a'][0]="app3";
	pat['z'][0]="zzzzz";
	pat['a'][1]="Apply now";
	
	int len=msg.length();
	for(int i=0;i<len;i++)
	{
		char beg=msg[i];
		for(int j=0; j<100 && !pat[beg][j].empty();j++)
		{
			cout<<pat[beg][j]<<endl;
			string::size_type t=msg.find(pat[beg][j],i);
			

			if(t!=string::npos)
				cout<<"match :"<<pat[beg][j]<<endl;
  		}
	}
	return 10;
}
