from CloudmusicApiMin import NetEase
from CloudmusicApiMin import Parse
from fuzzywuzzy import fuzz

api = NetEase()

#name = input()
#artist = input()
#album = input()
def get_lyric(name, artist, album, length):
	f = open("lyric.log",'w')
#	print(name,artist,album,length, file=f)
	datalist = api.search(name).get("songs", [])
#	print(datalist, file=f)
	match = fuzz.partial_token_set_ratio
	matches = []
	for item in datalist:
#		print(item, file=f)
		sim_name = match(name, item['name'])
		sim_full_name = fuzz.token_set_ratio(name,item['name'])
		for alias in item['alias']:
			sim_name = max(sim_name, match(name, alias))
			sim_full_name = max(sim_full_name, fuzz.token_set_ratio(name, alias))
		sim_artist = 0
		for arti in [artist['name'] for artist in item['artists']]:
			sim_artist = max(sim_artist, match(artist, arti))
		sim_album = match(album, item['album']['name'])
		#sim_duration = item['duration']/60000
		similarity = sim_name*0.7+sim_artist*0.2+sim_album*0.1
		matches.append((similarity, sim_name, sim_artist, sim_full_name, item['id']))
	matches.sort(reverse=True)
#	print(matches[0], file=f)
#	print('\n'.join(api.song_lyric(matches[0][4])),file=f)
	return '\n'.join(api.song_lyric(matches[0][4]))
#print()
