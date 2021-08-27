<?php
class article extends CI_Controller
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
    public function index($id){
        $this->db->where('id' , $id);
        $query = $this->db->get('content');
        $data['contents'] = $query->result_array();
        $this->load->view('article', $data);
    }
}