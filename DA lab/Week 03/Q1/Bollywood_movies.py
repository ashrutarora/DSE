#!/usr/bin/env python
# coding: utf-8

# In[161]:


import pandas as pd
import seaborn as sns
from matplotlib import pyplot as plt


# In[162]:


frame=pd.read_csv("bollywood.csv")
frame


# In[163]:


frame.shape


# In[164]:


frame["Genre"].str.strip().value_counts().sort_values(ascending= False)


# In[165]:


frame["Genre"].str.strip().value_counts().sort_values(ascending= True)


# In[166]:


frame["Genre"].str.strip().value_counts().idxmax()


# In[167]:


frame["Genre"].str.strip().value_counts().sort_values(ascending= True).idxmin()


# In[168]:


frame["Genre"].str.strip().value_counts().sort_values(ascending= True).nlargest(1)


# In[169]:


pd.crosstab(frame.Genre,frame.ReleaseTime)


# In[170]:


frame["Release Date"].dtype


# frame["Month"]=frame.Release Date.str.extract.(r'\b')

# In[171]:


frame["Release Date"]=pd.to_datetime(frame["Release Date"])
frame


# In[172]:


frame["month"]=frame["Release Date"].dt.month
frame


# In[ ]:





# In[173]:


frame[frame.Budget>=25].month.value_counts()


# In[174]:


frame["ROI"] = (frame.BoxOfficeCollection - frame.Budget) / frame.Budget
frame


# In[175]:


frame.corr()


# In[176]:


sns.boxplot(data=frame,y='Genre',x='YoutubeLikes')


# In[177]:


sns.pairplot(frame)


# In[178]:


feature_corre = ['Budget','BoxOfficeCollection','YoutubeViews','YoutubeLikes','YoutubeDislikes']
sns.heatmap(frame[feature_corre].corr(),annot=True);


# In[179]:


sns.barplot(frame.Genre,frame.BoxOfficeCollection)


# In[ ]:





# In[180]:


<AxesSubplot:xlabel='Genre', ylabel='BoxOfficeCollection'>


# In[ ]:


pd.crosstab(frame['Budget'],frame['Genre'])


# In[ ]:




