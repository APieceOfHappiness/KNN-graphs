import plotly.graph_objects as go
fig = go.Figure()
fig.update_layout(title='loss test _NNGraph_')
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.9979,10.0059,6.86252,5.43756,4.4906,3.76686,3.35591,3.17208,2.7306,2.49985]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'red'}, name='nngraph(1, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.8015,8.39394,4.69597,3.22539,2.46087,2.06193,1.9087,1.86059,1.84739,1.83051]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'green'}, name='nngraph(2, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.7207,8.13542,4.33983,2.65973,2.02484,1.873,1.84103,1.82547,1.85032,1.82317]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'blue'}, name='nngraph(3, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[34.7986,8.51477,3.9004,2.1111,1.86816,1.84828,1.8255,1.83348,1.83093,1.84512]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'yellow'}, name='nngraph(5, *)'))
X=[0,1,2,3,4,5,6,7,8,9]
Y=[35.1132,9.79718,3.70617,1.96512,1.83919,1.84423,1.83518,1.82673,1.82345,1.82649]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':3, 'color': 'black'}, name='nngraph(8, *)'))
fig.update_layout(title='Random graph')
fig.update_xaxes(title_text='parameter: mean neighbours', type='linear')
fig.update_yaxes(title_text='mean loss', type='linear')
fig.show()
