<html xmlns="http://www.w3.org/1999/html">
<head>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
</head>
<body>
<div class="row">

    <div class="col-xs-12">
        <input id="pac-location" class="form-control pac-input" type="text" placeholder="Type your location">
        <div id="location" class="mapBox"></div>

        <input class="loginInput" type="hidden" value="35.68,51.38,11" name="location" id="locationInput">
    </div>

    <hr>

</div>
<style>
    #location{
        height: 80%;
    }
    .mapBox {
        width: 100%;
        height: 250px;
    }

    .pac-controls label {
        font-family: Roboto;
        font-size: 13px;
        font-weight: 300;
    }

    .pac-input {
        background-color: #fff;
        font-family: Roboto;
        font-size: 12px;
        padding: 0 11px 0 13px;
        text-overflow: ellipsis;
        width: 200px;
        right: 5px;
        margin-top: 40px;
    }

    .pac-input:focus {
        border-color: #4d90fe;
    }
</style>
<script>
    var lat ;
    var lng ;
    var zoom ;
    var Loct ;

    function initAutocomplete() {

        //Loct = $('input#locationInput').val().split(',');

         //lat      = Loct[0];
         //lng      = Loct[1];
         //zoom     = Loct[2];


        var map = new google.maps.Map(document.getElementById('location'), {
            center: {lat : 35.68 , lng : 51.38},
            zoom: 11
        });


        // Create the search box and link it to the UI element.
        var input = document.getElementById('pac-location');
        var searchBox = new google.maps.places.SearchBox(input);
        map.controls[google.maps.ControlPosition.TOP_LEFT].push(input);

        // Bias the SearchBox results towards current map's viewport.
        map.addListener('bounds_changed', function() {
            searchBox.setBounds(map.getBounds());
        });

        var MarkerA = new google.maps.Marker({
            position: new google.maps.LatLng(lat , lng),
            draggable: true
        });
        MarkerA.setMap(map);
        google.maps.event.addListener(MarkerA, 'dragend', function (evt) {
            var InfoA = evt.latLng.lat().toFixed(10)+','+evt.latLng.lng().toFixed(10)+','+map.getZoom();
            $('input#locationInput').val(InfoA);
        });

        searchBox.addListener('places_changed', function() {
            var places = searchBox.getPlaces();
            if (places.length == 0) {
                return;
            }
            var bounds = new google.maps.LatLngBounds();
            places.forEach(function(place) {
                if (!place.geometry) {
                    console.log("Returned place contains no geometry");
                    return;
                }

             var latitude = place.geometry.location.lat();
                var longitude = place.geometry.location.lng();

                MarkerA.setMap(null);

                MarkerA = new google.maps.Marker({
                    position: new google.maps.LatLng(latitude, longitude),
                    draggable: true,
                    map: map
                });
                MarkerA.setMap(map);
                $('input#locationInput').val(latitude+','+longitude+','+zoom);

                if (place.geometry.viewport) {
                    bounds.union(place.geometry.viewport);
                } else {
                    bounds.extend(place.geometry.location);
                }



            });
            map.fitBounds(bounds);

        });

    }

</script>

<script src="https://maps.googleapis.com/maps/api/js?key=AIzaSyB7XWWgxE3Me8tvl-b-_jhd0qmbSzen2gY&libraries=places&callback=initAutocomplete"
        async defer></script>

</body>
</html>