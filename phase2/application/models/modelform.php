<?php
class modelform extends CI_Model
{
    public function __construct() {
        parent::__construct();
        $this->load->db('member');
        $this->load->db('admin');
    }

}
?>