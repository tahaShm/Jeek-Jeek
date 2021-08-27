<?php
    class category extends CI_Controller
    {
        public function __construct()
        {
            parent::__construct();
            $this->load->helper(array('form', 'url'));
            $this->load->database();
            $this->load->model('connect');
            $this->load->library('session');
            $this->load->helper('form');
        }
        public function start()
        {
            $_SESSION['page_number']=1;
            $this->db->order_by('id' , 'asc');

            $query = $this->db->get('content');
            $data['contents'] = $query->result_array();

            $this->load->view('category', $data);
        }
        public function index($page_number)
        {
            $_SESSION['page_number']=$page_number;
            $this->db->where('showing' , 1);
            $_SESSION['count']=$this->db->count_all_results('content');
            $this->db->order_by('id' , 'asc');
            $query=$this->db->get('content', 3,($page_number*3)-3 );
            $data['contents'] = $query->result_array();

            $this->load->view('category', $data);
        }
        public function topic($topic , $page_number){
            $_SESSION['topic']= $topic;
            $this->db->where('topic' , $topic );
            $this->db->where('showing' , 1);
            $_SESSION['count_top']=$this->db->count_all_results('content');
            $this->db->where('topic' , $topic );
            $this->db->where('showing' , 1);
            $query = $this->db->get('content',3,($page_number*3)-3);
            $data['contents'] = $query->result_array();
            //$_SESSION['count_top']=count($query->result_array());
            $this->load->view('topic', $data);
        }


        public function add_like(){
            $id = $this->input->post('id');
            $num = $this->input->post('num');
            $ipaddress = $this->input->ip_address();

            $this->db->where('ip' , $ipaddress);
            $this->db->where('id_content' , $id);
            $query =$this->db->get('likes');
            $InfoLike = $query->result_array();

            if(count($InfoLike) < 1){

                $dataLike['ip'] = $ipaddress;
                $dataLike['id_content'] = $id;
                $this->db->insert('likes',$dataLike);

                $data['likes'] = $num + 1;
                $this->db->where('id' , $id);
                $this->db->update('content',$data);

                echo 1;

            }else{
                echo 0;
            }

        }
        public function temp()
        {
            $this->load->view('template');

        }
        public function map()
        {
            $this->load->library('googlemaps');

//            $config['center'] = '35.7715983,51.3723554';
//            $config['zoom'] = 'auto';
//            $config['directions'] = TRUE;
//            $config['directionsStart'] = '35.7715983,51.3723554';
//            $config['directionsEnd'] = '35.7640079,51.4997525';
//            $config['directionsDivID'] = 'directionsDiv';
//              $config['placesAutocompleteInputID'] = 'myPlaceTextBox';
//              $config['placesAutocompleteBoundsMap'] = TRUE; // set results biased towards the maps viewport
//              $config['placesAutocompleteOnChange'] = 'map_.setCenter(this.getPlace().geometry.location);';
//            $this->googlemaps->initialize($config);
//            $data['map'] = $this->googlemaps->create_map();

            $config['center'] = '35.7715983,51.3723554';
            $config['zoom'] = 'auto';
            $config['places'] = TRUE;
            $config['placesAutocompleteInputID'] = 'myPlaceTextBox';
            $config['placesAutocompleteBoundsMap'] = TRUE; // set results biased towards the maps viewport
            $config['placesAutocompleteOnChange'] = 'Myplace()';
            $this->googlemaps->initialize($config);
            $data['map'] = $this->googlemaps->create_map();
            $this->load->view('map', $data);

       }
    }