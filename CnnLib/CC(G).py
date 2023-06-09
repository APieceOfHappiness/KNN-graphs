import plotly.graph_objects as go
fig = go.Figure()
X=[5,10,15]
Y=[None,0.0453593,0.031846]
fig.add_trace(go.Scatter(x=X, y=Y, mode='lines', line={'width':5, 'color': 'blue'}, name='ccs'))
fig.show()
