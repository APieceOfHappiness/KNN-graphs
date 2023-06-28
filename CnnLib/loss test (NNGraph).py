import plotly.graph_objects as go
fig = go.Figure()
fig.update_layout(title='loss test (NNGraph)')
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.8285,9.62125,6.94198,5.27061,4.37759,3.78744,3.43281,3.03075,2.53843,2.68647]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'red'}, name='nngraph(1, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.7084,8.58974,4.70217,3.39377,2.41328,2.13401,1.93651,1.88344,1.87766,1.84523]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'green'}, name='nngraph(2, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.5414,8.45759,4.42591,2.66411,2.11461,1.87893,1.85754,1.85616,1.85502,1.86608]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'blue'}, name='nngraph(3, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.459,8.85353,4.3845,2.36529,1.8917,1.84271,1.86385,1.87051,1.85946,1.83882]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'yellow'}, name='nngraph(5, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[35.0373,9.65692,4.04868,1.99911,1.88461,1.86932,1.85146,1.83914,1.82712,1.8647]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'black'}, name='nngraph(8, *)'))
fig.update_layout(title='Random graph')
fig.update_xaxes(title_text='parameter: mean neighbours', type='linear')
fig.update_yaxes(title_text='mean loss', type='linear')
fig.show()
